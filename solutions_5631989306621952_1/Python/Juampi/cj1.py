class TestCase:
    def __init__(self, s):
        self.s = s
    def solve(self):
        final = ""
        for c in self.s:
            if final == "":
                final = final + c
            elif c < final[0]:
                final = final + c
            else:
                final = c + final
        return final

def read_data(filename):
    with open(filename) as f:
        num_test_cases = int(next(f))
        test_cases = []
        for _ in range(num_test_cases):
            S = next(f).strip()
            test_case = TestCase(S)
            test_cases.append(test_case)
    return num_test_cases, test_cases

if __name__ == "__main__":
    num_test_cases, test_cases = read_data("aaa-large.in")
    for it in range(num_test_cases):
        test_case = test_cases[it]
        print("Case #{}:".format(it + 1), test_case.solve())
