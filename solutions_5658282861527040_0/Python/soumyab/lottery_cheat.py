T = int(input())

format_string = "Case #{0}: {1}"

for i in range(T):
    next_line = input().split()

    A = int(next_line[0])
    B = int(next_line[1])
    K = int(next_line[2])
    answer = 0
    a = 0
    b = 0

    while a < A:
        b = 0
        while b < B:
            if a & b < K:
                answer += 1
            b += 1
        a += 1

    print(format_string.format(i+1, answer))
