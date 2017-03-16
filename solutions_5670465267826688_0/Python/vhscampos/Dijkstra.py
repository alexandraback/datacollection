import sys

M = dict()
M[1] = {1: 1, 2: 2, 3: 3, 4: 4}
M[2]= {1: 2, 2: -1, 3: 4, 4: -3}
M[3] = {1: 3, 2: -4, 3: -1, 4: 2}
M[4] = {1: 4, 2: 3, 3: -2, 4: -1}

def solvebf(T):
    valuei = 1
    for i in range(len(T)-2):
        if valuei > 0:
            valuei = M[valuei][T[i]]
        else:
            valuei = -M[-valuei][T[i]]

        if valuei != 2:
            continue

        valuej = 1
        for j in range(i+1, len(T)-1):
            if valuej > 0:
                valuej = M[valuej][T[j]]
            else:
                valuej = -M[-valuej][T[j]]

            if valuej != 3:
                continue

            valuek = 1
            for vk in T[j+1:]:
                if valuek > 0:
                    valuek = M[valuek][vk]
                else:
                    valuek = -M[-valuek][vk]

                if valuek != 4:
                    continue

                return True

    return False


def solve(instance):
    S = instance
    T = []
    for c in S:
        if c == 'i':
            T.append(2)
        elif c == 'j':
            T.append(3)
        else:
            T.append(4)

    if len(T) < 3:
        print('NO')
        return

    result = 1

    for c in T:
        if result > 0:
            new_result = M[result][c]
        else:
            new_result = -M[-result][c]

        result = new_result

    if result == -1:
        if solvebf(T):
            print('YES')
            return

    print('NO')


if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())
    IL = []
    for i in range(T):
        line = sys.stdin.readline().strip().split()
        X = int(line[1])
        line = list(sys.stdin.readline().strip())
        S = X * line

        IL.append(S)

    for i in range(T):
        print('Case #'+str(i+1)+': ', end='')
        solve(IL[i])

