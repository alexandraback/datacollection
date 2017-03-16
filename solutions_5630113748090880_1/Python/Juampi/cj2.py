class TestCase:
    def __init__(self, N, l):
        self.N = N
        self.lists = l
    def solve(self):
        missing = []
        for height in range(1, 2501):
            count = 0
            for l in self.lists:
                for n in l:
                    if n == height:
                        count += 1
            if count % 2 == 1:
                missing.append(height)
        missing.sort()
        return " ".join(str(e) for e in missing)

def read_data(filename):
    with open(filename) as f:
        num_test_cases = int(next(f))
        test_cases = []
        for _ in range(num_test_cases):
            N = int(next(f))
            lists = []
            for _ in range(2*N - 1):
                l = [int(n) for n in next(f).split()]
                lists.append(l)
            test_case = TestCase(N, lists)
            test_cases.append(test_case)
    return num_test_cases, test_cases

if __name__ == "__main__":
    num_test_cases, test_cases = read_data("b2l.in")
    for it in range(num_test_cases):
        test_case = test_cases[it]
        print("Case #{}:".format(it + 1), test_case.solve())
