import fileinput

def solve(tests):
    N = int(tests.readline())
    M = []

    roots = []
    matrix = [[False]*N for i in range(0,N)]
    dfs = [set() for i in range(0,N)]

    process = lambda test: filter(lambda x: x != -1, map(lambda x, y: y if x else -1, test, range(0, len(test))))

    for i in range(0,N):
        data = tests.readline().split()
        M.append(int(data.pop(0)))

        if M[i] == 0:
            roots.append(i)

        for j in data:
            matrix[int(j)-1][i] = True

    for i in roots:
        queue = process(matrix[i])
        for j in queue:
            queue.extend(process(matrix[j]))
            if i in dfs[j]:
                return "Yes"
            else:
                dfs[j].add(i)

    return "No"


if __name__ == "__main__":
   tests = fileinput.FileInput()
   T = int(tests.readline())

   for i in range(0,T):
        print "Case #{}: {}".format(i+1, solve(tests))
