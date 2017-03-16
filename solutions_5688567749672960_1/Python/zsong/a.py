# def solve(x):
# m = 1
# counter = 1
# counter_flip = 0
# while m <= x:
# if m == x:
# break
#
# n = m + 1
# flip = int(str(m)[::-1])
#
#         if flip > m and flip < x:
#             m = flip
#             counter_flip += 1
#         else:
#             m = n
#         counter += 1
#     #     print(m)
#     # print(counter, counter_flip)
#     return counter - counter_flip + 1


def solve(x):
    if str(x)[-1] == '0':
        return solve(x - 1) + 1

    # print(x)
    if x <= 11:
        return x

    s = str(x)
    length = len(s)
    half = length // 2

    first, second = s[0:half], s[half:]
    # print(first, second)

    if int(first[::-1]) == 1:
        return (int(second) - 1) + solve(10 ** (length - 1) + 1 - 2) + 2

    return int(first[::-1]) - 1 + (int(second) - 1) + 1 + solve(10 ** (length - 1) + 1 - 2) + 2


def solve_slow(x):
    queue = [(x, 1)]
    memo = {}

    while queue:
        (c, counter) = queue.pop(0)
        # print(c, counter)
        if c == 1:
            return counter

        flip = str(c)[::-1]
        # print(flip)

        if flip[0] != '0':
            if int(flip) not in memo and int(flip) < c:
                queue.append((int(flip), counter + 1))
                memo[int(flip)] = 1

        if c - 1 not in memo:
            queue.append((c - 1, counter + 1))
            memo[c - 1] = 1


if __name__ == "__main__":
    testcases = int(input())

    for caseNr in range(1, testcases + 1):
        x = int(input())
        print("Case #%i: %s" % (caseNr, solve(x)))