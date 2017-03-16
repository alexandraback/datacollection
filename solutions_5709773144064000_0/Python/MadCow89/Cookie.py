import math

def solve(input_path, output_path):
    with open(input_path, 'r') as fin:
        with open(output_path, 'w') as fout: 
            num_cases = int(fin.readline())
            for i in xrange(num_cases):
                c, f, x = map(lambda s : float(s), fin.readline().strip().split(" "))
                fout.write("Case #" + str(i+1) + ": " + "{0:.7f}".format(process(c, f, x)) + "\n")

def process(c, f, x):
    num_farms = max(0, int(math.ceil(x/c - 2.0/f - 1)))
    return sum(map(lambda t : c/(2 + t*f), xrange(num_farms))) + x / (2 + num_farms*f)

dir = "F:\\Sync\\Dropbox\\Coding\\CodeJam\\2014\\"
input_path = dir + "B-small-attempt0.in"
output_path = dir + "cookie.out"
solve(input_path, output_path)
