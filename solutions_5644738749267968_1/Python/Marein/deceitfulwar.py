import sys
import copy

class Logger:
    """
    Log to a file as well as the standard console
    """

    def __init__(self, filename, use_console=True):
        self.console = sys.stdout
        self.log = open(filename, 'w')
        self.use_console = use_console

    def write(self, content):
        if self.use_console: self.console.write(content)
        self.log.write(content)

    def flush(self):
        if self.use_console: self.console.flush()

problem = "D-large"
filename = "{}.in".format(problem)
sys.stdout = Logger("{}.out".format(problem))

with open(filename) as file:

    def readint():
        return int(file.readline())

    def readfloats(sep=" "):
        return list(map(float,file.readline().strip().split(sep)))

    nr_of_cases = readint()

    for case_nr in range(1,nr_of_cases+1):

        N = readint()

        masses_naomi = sorted(readfloats())
        masses_ken = sorted(readfloats())

        tokens = "".join(list(map(lambda x: x[1],sorted(list(zip(masses_naomi,'n'*N))+list(zip(masses_ken,'k'*N))))))
        while 'nk' in tokens:
            tokens = tokens.replace('nk','')
        normal_score = int(len(tokens)/2)

        deceitful_score = 0
        while masses_naomi != []:

            if masses_naomi[0] > masses_ken[0]:

                masses_naomi = masses_naomi[1:]
                masses_ken = masses_ken[1:]
                deceitful_score += 1

            else:

                masses_naomi = masses_naomi[1:]
                masses_ken = masses_ken[:-1]

        print("Case #{}: {} {}".format(case_nr,deceitful_score,normal_score))