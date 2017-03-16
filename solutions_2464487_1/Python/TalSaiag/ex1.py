from math import sqrt, floor
class Problem(object):
    def __init__(self, r, t):
        self.r = r
        self.t = t

def getSolution(problem):
    a_1 = 2 * problem.r + 1
    b = 2 * a_1 - 4
    c = -8 * problem.t
    delta = sqrt(b*b - 4 * c)
    count = 0.5 * (-b + delta) * 0.25
    return str(int(floor(count)))

def readProblem(input_file):
    r, t = [int(x) for x in input_file.readline().split(" ")]
    return Problem(r, t)

def executeFile(file_path):
    input_file = file(file_path, "r")
    output_file = file(file_path + ".out", "w")
    count = int(input_file.readline());
    index = 0
    while (index < count):
        problem = readProblem(input_file)
        sol = getSolution(problem)
        output_file.write("Case #" + str(index + 1) + ": " + sol + "\n")
        index = index + 1
    output_file.close()

def main():
    import sys
    if (len(sys.argv) < 2):
        print "Wrong number of arguments!\n" + \
              "Arguments: file_path"
        return
    for i in xrange(len(sys.argv) - 1):
        executeFile(sys.argv[i + 1])
    
if (__name__ == "__main__"):
    main()
