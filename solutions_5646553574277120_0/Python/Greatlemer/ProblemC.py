# Written for Python 2.7.9

from optparse import OptionParser
from StringIO import StringIO
import sys

# Expected format of TEST_CASES is a list of tuples of (input, expected_output)
TEST_CASES = [("""4
1 2 3
1 2
1 3 6
1 2 5
2 1 3
3
1 6 100
1 5 10 25 50 100
""","""Case #1: 0
Case #2: 1
Case #3: 1
Case #4: 3
""")]

def parse_input(input_reader):
    case_count = int(input_reader.readline())
    case_idx = 0
    while case_count > case_idx:
        case_idx += 1
        input_values = {"case": case_idx,}
        parts = input_reader.readline().strip().split()
        input_values['max_coins'] = int(parts[0])
        input_values['denom_count'] = int(parts[1])
        input_values['max_value'] = int(parts[2])
        denominations = input_reader.readline().strip().split()
        assert input_values['denom_count'] == len(denominations)
        input_values['denominations'] = [int(d) for d in denominations]
        yield input_values


def solve_problem(
    max_coins, denom_count, max_value, denominations,
    output_writer=sys.stdout, **kwargs
):
    case = kwargs['case']
    new_coins = 0
    target_value = 1
    denom_index = 1
    if denominations[0] != 1:
        new_coins += 1
        denom_index = 0
    largest_available_so_far = max_coins
    while target_value <= max_value:
        while (
            denom_index < denom_count
        ) and (
            largest_available_so_far < target_value
        ) and (
            denominations[denom_index] <= (largest_available_so_far + 1)
        ):
            largest_available_so_far += (denominations[denom_index] * (max_coins))
            denom_index += 1
        if largest_available_so_far < target_value:
            next_new_coin = largest_available_so_far + 1
            largest_available_so_far += (next_new_coin * max_coins)
            new_coins += 1
        target_value = largest_available_so_far + 1
    print >>output_writer, "Case #%d: %s" % (case, new_coins)

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