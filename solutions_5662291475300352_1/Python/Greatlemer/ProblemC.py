# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""3
4
1 1 12
359 1 12
2 1 12
358 1 12
2
180 1 100000
180 1 1
1
180 2 1
""","""Case #1: 0
Case #2: 1
Case #3: 0
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        groups = int(input_reader.readline())
        group_data = []
        total_hikers = 0
        for group in range(groups):
            group_info = {}
            parts = input_reader.readline().split()
            group_info['start_pos'] = int(parts[0])
            group_info['hikers'] = int(parts[1])
            group_info['min_loop_time'] = int(parts[2])
            group_data.append(group_info)
            total_hikers += group_info['hikers']
        input_values['groups'] = groups
        input_values['group_data'] = group_data
        input_values['total_hikers'] = total_hikers
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    groups = kwargs['groups']
    group_data = kwargs['group_data']
    total_hikers = kwargs['total_hikers']
    answer = ""
    hiker_info = []
    for group in group_data:
        min_loop_time = group['min_loop_time']
        hikers = group['hikers']
        start_pos = group['start_pos']
        for loop_time in range(min_loop_time, min_loop_time + hikers):
            # Everything multiplied by 360 to avoid floats
            time_to_start = ((360 - start_pos) * loop_time)
            hiker_info.append((time_to_start, loop_time * 360, start_pos))
    hiker_info.sort()
    answer = total_hikers - 1
    for index in range(1, total_hikers):
        # We overtake everyone slower than the one we're looking at.
        passes = total_hikers - index - 1
        # Time for the one we follow to get to our finish point.
        time_to_start = hiker_info[index][0]
        # See how many times the faster ones lap us.
        for hiker in hiker_info[:index]:
            extra_time = time_to_start - hiker[0]
            laps = extra_time / hiker[1]
            passes += laps
            if passes > answer:
                break
        if passes < answer:
            answer = passes

    print >>output_writer, "Case #%d: %s" % (case, answer)

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