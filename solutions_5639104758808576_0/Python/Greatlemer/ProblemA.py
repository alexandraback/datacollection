# Written for Python 2.7.5

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""4
4 11111
1 09
5 110011
0 1
""","""Case #1: 0
Case #2: 1
Case #3: 2
Case #4: 0
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        # Implementation of parsing code goes here.
        input_values = {"case": case_idx,}
        case_line = input_reader.readline().strip()
        s_max, s_levels = case_line.split()
        input_values['s_max'] = int(s_max)
        input_values['s_levels'] = [int(s) for s in s_levels]
        yield input_values


def solve_problem(output_writer=sys.stdout, **kwargs):
    case = kwargs['case']
    s_max = kwargs['s_max']
    s_levels = kwargs['s_levels']
    extras_needed = 0
    audience_size = 0
    for index, member_count in enumerate(s_levels):
        if audience_size < index:
            difference = index - audience_size
            extras_needed += difference
            audience_size += difference
        audience_size += member_count
    # Implementation of code to solve the problem goes here.
    answer = "{0}".format(extras_needed)
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