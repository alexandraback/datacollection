import sys
import math

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

problem = "C-small-attempt5"
filename = "{}.in".format(problem)
sys.stdout = Logger("{}.out".format(problem))

with open(filename) as file:

    def readint():
        return int(file.readline())

    def readints(sep=" "):
        return list(map(int,file.readline().strip().split(sep)))

    def groups(list, width):
        return [list[group_start:group_start+width] for group_start in range(0,len(list),width)]

    def checkonedim(r,c,m):

        if m == r*c:

            return None

        else:

            result = list('*'*m)+list('.'*(r*c-m))
            result = groups(result,c)
            result[r-1][c-1] = 'c'
            return result

    def checkpatch(r,c,m,recursive=False):

        # so many cases... this MUST be generalizable, right? right..?

        inner_area = int(math.fabs(r-2) * math.fabs(c-2)) # size of area that does not need to be empty

        if m + 1 == r*c:

            result = list('*'*(c*r))
            result = groups(result,c)
            result[r-1][c-1] = 'c'
            return result

        if r < 2 or c < 2:

            return None

        if m >= min(r,c):

            if r < c:
                patch = checkpatch(r, c-1, m-r, True)
                return None if patch is None else list(map(lambda x: ['*']+x, patch))
            else:
                patch = checkpatch(r-1, c, m-c, True)
                return None if patch is None else [list('*'*c)]+patch

        elif m == 0:

            patch = list('.'*(c*r))
            patch = groups(patch,c)
            patch[r-1][c-1] = 'c'

            return patch

        elif m <= inner_area:

            inner = list('*'*m)+list('.'*(inner_area-m))
            inner = groups(inner,c-2)

            inner = inner + 2*[list('.'*(c-2))]
            inner = list(map(lambda x: x+list('.'*2),inner))
            inner[r-1][c-1] = 'c'

            return inner

        else:

            return None

    nr_of_cases = readint()

    for case_nr in range(1,nr_of_cases+1):

        print("Case #{}:".format(case_nr))

        R,C,M = readints()

        result = checkonedim(R,C,M) if min(R,C) == 1 else checkpatch(R,C,M)

        if result == None:

            print("Impossible")

        else:

            print("".join(map(lambda x: x+'\n',map("".join,result))).strip())