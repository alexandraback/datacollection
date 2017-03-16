from optparse import OptionParser
import string

def solve(N,J):
    total_points = sum(J)
    total_spare = total_points
    result = ["0.000000"] * N
    to_allocate = dict([(i,J[i]) for i in range(N)])
    n_changed = True
    while(n_changed):
        n_changed = False
        points_each = float(total_points + total_spare) / N
        for k,v in to_allocate.items():
            extra_needed = points_each - v
            val = float(extra_needed * 100) / total_points
            if val < 0:
                val = 0
                N -= 1
                total_spare -= v
                del to_allocate[k]
                n_changed = True
                break
            result[k] = "{:f}".format(val)
    return " ".join(result)


def parse_case(data_line):
    bits = data_line.split()
    N = int(bits[0])
    J = [int(x) for x in bits[1:]]
    return N,J

def main():
    parser = OptionParser()
    parser.add_option("-f", "--file", dest="filename",
                      help="read input from FILE", metavar="FILE")

    (options, args) = parser.parse_args()
    if not options.filename:
        parser.error("Must provide a filename.")
    input_file = open(options.filename, "r")
    total_cases = int(input_file.readline())
    case_number = 0
    while case_number < total_cases:
    	case_number += 1
    	data_args = parse_case(input_file.readline())
    	print "Case #%d: %s" % (case_number, solve(*data_args))

if __name__ == "__main__":
	main()