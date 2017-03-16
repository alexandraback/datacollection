# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys
from math import ceil, pow

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""5
1
3
4
1 2 1 2
1
4
6
9 9 9 9 9 9
3
8 8 8
""","""Case #1: 3
Case #2: 2
Case #3: 3
Case #4: 9
Case #5: 7
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        input_values['diners'] = int(input_reader.readline().strip())
        pancakes = input_reader.readline().strip()
        input_values['pancakes'] = [int(x) for x in pancakes.split()]
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    diners = kwargs['diners']
    pancakes = sorted(kwargs['pancakes'])
    minutes_needed = pancakes[-1]
    max_minutes_needed = minutes_needed
    # We don't save any time moving pancakes when there's fewer than 4
    # so only try to do so if that's not the case.
    if pancakes[-1] > 3:
        extra_minutes = 0
        total_pancakes = sum([pancake for pancake in pancakes if pancake > 3])
        optimal_stack_size = int(ceil(pow(total_pancakes, 0.5)))
        while pancakes[-1] > optimal_stack_size:
            if pancakes[-1] > (optimal_stack_size * 2):
                to_remove = optimal_stack_size
            else:
                to_remove = pancakes[-1] / 2
            pancakes[-1] -= to_remove
            pancakes.append(to_remove)
            extra_minutes += 1
            pancakes.sort()
        if extra_minutes > 0:
            minutes_needed = pancakes[-1] + extra_minutes
    if minutes_needed > max_minutes_needed:
        minutes_needed = max_minutes_needed
    answer = "{0}".format(minutes_needed)
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