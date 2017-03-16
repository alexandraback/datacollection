import operator

class Problem(object):
    def __init__(self, E, R, N, values):
        self.E, self.R, self.N, self.values = E, R, N, values

def getSolution(problem):
    E_1 = problem.E + 1
    mat_val = [0 for i in xrange(E_1)]
    for chore_index_rev in xrange(problem.N):
        chore_index = problem.N - chore_index_rev - 1
        mat_val = [max([(mat_val[min(problem.E, energy_have - energy_put + problem.R)] + problem.values[chore_index] * energy_put) for energy_put in xrange(energy_have + 1)]) for energy_have in xrange(E_1)]
    return str(mat_val[problem.E])

def readProblem(input_file):
    E, R, N = [int(x) for x in input_file.readline().split(" ")]
    values = [int(x) for x in input_file.readline().split(" ")]
    return Problem(E, R, N, values)

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
