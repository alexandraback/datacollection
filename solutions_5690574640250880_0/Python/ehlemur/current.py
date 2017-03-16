from itertools import product


def join():
    global R, output

    for i in range(R):
        output[i] = "".join(output[i])
    output = "\n".join(output)


T = int(input())

for t in range(1, T + 1):
    R, C, M = map(int, input().split())

    if M == 0:
        output = [["."] * C  for i in range(R)]
        output[0][0] = 'c'
        join()

    elif R == 1:
        output = "c"
        for i in range(C - M - 1):
            output += "."
        for i in range(M):
            output += "*"

    elif C == 1:
        output = "c\n"
        for i in range(R - M - 1):
            output += ".\n"
        for i in range(M):
            output += "*\n"
        output = output[:-1]

    elif M == R * C - 1:
        output = [["*"] * C  for i in range(R)]
        output[0][0] = 'c'
        join()

    elif M <= R * C - 4:
        output = [["*"] * C  for i in range(R)]

        left = R * C - M

        for i in range(1, R):
            for j in range(1, C):
                if 2 * ((i - 1) + (j - 1)) + 4 <= left <= (i + 1) * (j + 1):
                    left += 4
                    for a in range(i + 1):
                        if left == 0:
                            break
                        left -= 2
                        output[a][0] = output[a][1] = '.'

                    for b in range(j + 1):
                        if left == 0:
                            break
                        left -= 2
                        output[0][b] = output[1][b] = '.'

                    for a, b in product(range(2, i + 1), range(2, j + 1)):
                        if left == 0:
                            break
                        left -= 1
                        output[a][b] = '.' 

                    assert(left == 0)

        output[0][0] = 'c'

        if left == 0:
            join()
        else:
            output = "Impossible"

    else:
        output = "Impossible"

    # print(R, C, M)
    print("Case #{}:\n{}".format(t, output))
