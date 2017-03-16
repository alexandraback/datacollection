#!/usr/bin/env python3

def slides(B, M):
    if M > 2**(B-2):
        return []

    # Start with all nodes going to subsequent nodes.
    result = [B * [0] for _ in range(B)]
    for i in range(B-1):
        for j in range(i+1, B):
            result[i][j] = 1

    for i in range(1, B-1):
        if 0 == (M-1) & (1 << (i-1)):
            result[0][B-1-i] = 0
    return result

def oracle(B, M, result):
    if result:
        assert(len(result) == B)

        for i, row in enumerate(result):
            assert(row[i] == 0)
            assert(len(row) == B)

        # No buildings may originate from building B.
        for i in result[B-1]:
            assert(i == 0)

        # No loops, else infinite.
        assert(not has_loops(result, 0, []))

    else:
        # Prove it's impossible
        pass

def has_loops(graph, start, seen):
    if start in seen:
        return True

    for (i, e) in enumerate(graph[start]):
        if e == 1 and has_loops(graph, i, seen + [start]):
            return True

    return False

if __name__ == '__main__':
    T = int(input())
    for i in range(1, T+1):
        B, M = map(int, input().split())

        result = slides(B, M)
        oracle(B, M, result)

        if not result:
            output = 'IMPOSSIBLE'
        else:
            output = 'POSSIBLE'
            for row in result:
                output += '\n' + ''.join([str(i) for i in row])

        print("Case #{}: {}".format(i, output))
