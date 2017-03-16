# Written for Python 2.7.5

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""4
3 2
10001
20000
10000
1 2
2 3
5 4
36642
28444
50012
29651
10953
1 4
2 3
2 5
4 5
5 5
36642
28444
50012
29651
10953
1 2
1 4
2 3
2 5
4 5
6 6
10001
10002
10003
10004
10005
10006
1 2
1 6
2 3
2 4
3 5
4 5
""","""Case #1: 100002000010001
Case #2: 1095328444500122965136642
Case #3: 1095328444366422965150012
Case #4: 100011000210003100041000510006
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_bits = input_reader.readline().rstrip("\n").split(" ")
        city_idx = 0
        city_count = int(input_bits[0])
        flight_count = int(input_bits[1])
        codes = [None]
        while city_count > city_idx:
            city_idx += 1
            codes.append(int(input_reader.readline()))
        flight_idx = 0
        links = dict([(code, set()) for code in codes[1:]])
        while flight_count > flight_idx:
            flight_idx += 1
            input_bits = input_reader.readline().rstrip("\n").split(" ")
            city1 = codes[int(input_bits[0])]
            city2 = codes[int(input_bits[1])]
            links[city1].add(city2)
            links[city2].add(city1)
        input_values = {"case": case_idx,
                        "lowest": min(codes[1:]),
                        "links": links
                       }
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    lowest = kwargs['lowest']
    links = kwargs['links']
    codes = set(links.keys())
    target_count = len(links)
    success, visited = solve_for_state(links, [lowest], [lowest], codes)
    msg = "".join([str(code) for code in visited])

    print >>output_writer, "Case #%d: %s" % (case, msg)

def solve_for_state(links, visited, trip_stack, codes):
    codes_left = codes.difference(visited)
    if not codes_left:
        return True, visited
    else:
        for code in sorted(codes_left):
            idx = len(trip_stack)
            while idx > 0:
                idx -= 1
                if code in links[trip_stack[idx]]:
                    if code in visited:
                        new_visited = visited
                    else:
                        new_visited = visited + [code]
                    new_stack = trip_stack[:idx+1] + [code]
                    can_solve, route = solve_for_state(links, new_visited, new_stack, codes)
                    if can_solve:
                        return True, route
        return False, []

def solve_inputs(input_reader, output_writer):
    """
    Loop through each problem input in input reader and solve it.

    Outputs responses to output_writer.
    """
    for input_values in parse_input(input_reader):
        solve_problem(output_writer=output_writer, **input_values)

def run_tests():
    idx = 0
    all_pass = True
    for problem_input, expected_output in TEST_CASES:
        idx += 1
        input_reader = StringIO(problem_input)
        output_writer = StringIO()
        solve_inputs(input_reader, output_writer)
        problem_output = output_writer.getvalue()
        if problem_output == expected_output:
            print "Test %d: Success" % idx
        else:
            all_pass = False
            print "Test %d: Failure" % idx
            print problem_output
        input_reader.close()
        output_writer.close()
    if all_pass:
        print "All tests were successful!"
    else:
        print "Something didn't match - try again."

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file",
                      dest="filename_stem",
                      help="read input from FILE.in and write to FILE.out",
                      metavar="FILE")

    (options, args) = parser.parse_args()
    if options.filename_stem:
        print "Running in file mode."
        input_reader = open("%s.in" % options.filename_stem, "r")
        output_writer = open("%s.out" % options.filename_stem, "w")
        solve_inputs(input_reader, output_writer)
    else:
        print "Running in test mode."
        run_tests()

if __name__ == "__main__":
    main()