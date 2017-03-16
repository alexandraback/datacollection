import sys

def InputIterator():
    for line in sys.stdin:
        for value in line.split(): yield value

def Fair(A, B):
    N = len(A)
    A, B = sorted(A), sorted(B)

    score = 0

    used = [False]*N
    for i in range(N):
        lose = False

        for j in range(N):
            if not used[j] and B[j] > A[i]:
                used[j] = True
                lose = True
                break

        if not lose:
            for j in range(N):
                if not used[j]:
                    used[j] = True
                    break
            score += 1

    return score

def Deceit(A, B):
    N = len(A)
    A, B = set(A), set(B)

    score = 0

    for g in range(N):
        if min(A) > min(B):
            A.remove(min(A))
            B.remove(min(B))
            score += 1
        else:
            A.remove(min(A))
            B.remove(max(B))

    return score

inp = InputIterator()
T = int(next(inp))

for t in range(T):
    N = int(next(inp))
    A, B = [], []

    for i in range(N): A.append(float(next(inp)))
    for i in range(N): B.append(float(next(inp)))

    print "Case #{0}:".format(t+1), Deceit(A, B), Fair(A, B)
