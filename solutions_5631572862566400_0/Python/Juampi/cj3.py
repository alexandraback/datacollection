from collections import defaultdict

def DFS(G,v,seen=None,path=None):
    if seen is None: seen = []
    if path is None: path = [v]

    seen.append(v)

    paths = []
    for t in G[v]:
        if t not in seen:
            t_path = path + [t]
            paths.append(tuple(t_path))
            paths.extend(DFS(G, t, seen, t_path))
    return paths

class TestCase:
    def __init__(self, N, G):
        self.N = N
        self.G = G
    def solve(self):
        longest_path_length = 0
        for v in range(1, self.N + 1):
            all_paths = DFS(self.G, v)
            max_path = list(max(all_paths, key=lambda l: len(l)))
            if self.G[max_path[-1]][0] != all_paths[-1][-2] and self.G[all_paths[-1][-1]][0] != all_paths[-1][0]:
                continue
            if self.G[max_path[-1]][0] == max_path[-2] and len(max_path) > 2:
                done = False
                while not done:
                    done = True
                    for v in range(1, self.N + 1):
                        if (self.G[v][0] == max_path[-1]) and (v not in max_path):
                            max_path.append(v)
                            done = False
                        elif (self.G[v][0] == max_path[0]) and (v not in max_path):
                            max_path = [v] + max_path
                            done = False
            if len(max_path) > longest_path_length:
                longest_path_length = len(max_path)
        return longest_path_length

def read_data(filename):
    with open(filename) as f:
        num_test_cases = int(next(f))
        test_cases = []
        for _ in range(num_test_cases):
            N = int(next(f))
            l = [int(e) for e in next(f).split()]
            G = defaultdict(list)
            for idx, val in enumerate(l):
                G[idx + 1].append(val)
            test_case = TestCase(N, G)
            test_cases.append(test_case)
    return num_test_cases, test_cases

if __name__ == "__main__":
    num_test_cases, test_cases = read_data("C-small-attempt4.in")
    for it in range(num_test_cases):
        test_case = test_cases[it]
        print("Case #{}:".format(it + 1), test_case.solve())
