import math
import fractions
import sys


def reduce(a, b):
    gcd = fractions.gcd(a, b)
    return [a / gcd, b / gcd]


def solve(a, b):
    a, b = reduce(a, b)
    if bin(b).count('1') != 1 or a == 0:
        return "impossible"
    div = b / (a * 1.0)
    gens = int(math.ceil(math.log(div) / math.log(2)))
    return "%s" % gens

if __name__ == "__main__":
    output_file = open("%s.%s" % (sys.argv[1].split(".")[0], "out"), "w")
    file_name = sys.argv[1]
    input_file = open(file_name)
    case_count = int(input_file.readline())
    for i in xrange(case_count):
        a, b = map(int, input_file.readline().strip().split("/"))
        result = solve(a, b)
        output_file.write("Case #%s: %s\n" % (i + 1, result))
    output_file.close()
    input_file.close()
    print "Done!"
