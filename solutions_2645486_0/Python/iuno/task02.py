import sys
import itertools
import collections

class MyInt:
    def __init__(self, value, neginf):
        self.value = value
        self.neginf = neginf

    def __add__(self, natural):
        return MyInt(self.value + natural, self.neginf)

    def __lt__(self, other):
        return not other.neginf and (self.neginf or self.value < other.value)

    def __str__(self):
        return "-inf" if self.neginf else str(self.value)

def simple(e, r, vs):
    OPT = [[MyInt(0, True) for i in range(e+1)] for j in range(len(vs)+1)]
    OPT[0][e] = MyInt(0, False)
    for i in range(len(vs)):
        for j in range(r, e+1):
            for k in range(max(0, j-r), e+1):
                temp = OPT[i][k] + (k+r-j) * vs[i]
                if OPT[i+1][j] < temp:
                    OPT[i+1][j] = temp

    #for i in OPT:
    #   print(", ".join(list(map(str, i))))

    return OPT[len(vs)][r].value




def read_input(path):
    Chest = collections.namedtuple('Chest', ['id', 'required', 'content'])

    with open(path) as f:
        lineiterator = iter(f)

        num_tests = int(next(lineiterator))

        for i in range(num_tests):


            e, r, n = list(map(int, next(lineiterator).split()))
            vs = list(map(int, next(lineiterator).split()))

            yield e, min(e, r), vs


def write_solutions(path, solutions):
    with open(path, "w") as f:
        for i, solution in zip(itertools.count(1), solutions):
            print("Case #{num}: {value}".format(num=i, value=str(solution)), flush=True)
            print("Case #{num}: {value}".format(num=i, value=str(solution)), file=f)


if __name__ == '__main__':
    todo = read_input(sys.argv[1])
    result = (simple(e, r, vs) for e, r, vs in todo)
    write_solutions(sys.argv[2], result)

