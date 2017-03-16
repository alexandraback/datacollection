# Solution to "Safety in Numbers" for Google Code Jam 2012
# by Peter Mattsson (quantum.caffeine@gmail.com)

from optparse import OptionParser

parser = OptionParser()
parser.add_option("-i", "--infile", dest="input", help="read input from FILE", metavar="FILE")
parser.add_option("-o", "--outfile", dest="output", help="write output to FILE", metavar="FILE")

(options, args) = parser.parse_args()

def get_case(data):
    num_cases = int(data[0])
    pos = 1
    for _ in range(num_cases):
	n = int(data[pos])
	points = [int(x) for x in data[pos+1:pos+1+n]]
	pos = pos+1+n
	yield n,points

input = open(options.input, 'r')
output = open(options.output, 'w')

case = 0

for n, points in get_case(input.read().split()):
    case += 1
    x = float(sum(points))
    sp = sorted([[points[y], y, 0.0] for y in range(len(points))], key=lambda point: point[0])
    print >> output, "Case #%d:" % case,
    for c in range(len(points)):
	y_rem = 1.0
	m = 0
	result = 0
	while m < len(points):
	    if sp[m][0] < points[c]:
		sp[m][2] = (points[c]-sp[m][0])/x
		y_rem -= sp[m][2]
		m += 1
	    else:
		break
	pts = points[c]
	if m != len(points) and y_rem > 0:
	    while m < len(points):
		if sp[m][1] == c:
		    m += 1
		    continue
		next = float(sp[m][0] - pts)/x
		if float(next)*m > y_rem:
		    result += y_rem/float(m)
		    y_rem = 0
		    break
		else:
		    result += next
		    pts += next*x
		    y_rem -= float(next)*(m)
		    m += 1
	if y_rem > 0:
	    result += y_rem/n
	result *= 100.0
	#result = (float(2*x-n*points[c])/float(n*x))*100.0
	#if result < 0.0:
	    #result = 0.0
	print >> output, "%f" % result,
    print >> output

input.close()
output.close()