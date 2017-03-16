input = open(file = "input.txt", mode = 'r')
output = open(file = "output.txt", mode = 'w')
t = int(input.readline().rstrip())
r, n, m, k = list(map(int, input.readline().rstrip().split()))
output.write("Case #1:\n")
lolka = [2, 3, 4, 5]
for i in range(r):
    A = list(map(int, input.readline().rstrip().split()))
    answer = []
    for elem in lolka:
        if elem in A and elem != 4:
            answer.append(elem)
    for elem1 in lolka:
        for elem2 in lolka:
            for elem3 in lolka:
                if elem1 * elem2 * elem3 in A:
                    if (elem1 * elem2 * elem3) % 4 == 1:
                        answer += [elem1] * (1 - answer.count(elem1)) + [elem2] * (1 - answer.count(elem2)) + [elem3] * (1 - answer.count(elem3))
    #print(answer)
    for elem1 in lolka:
        for elem2 in lolka:
            if elem1 * elem2 in A:
                if elem1 == elem2:
                    if elem1 != 2:
                        answer += [elem1] * (2 - answer.count(elem1))
                else:
                    answer += [elem1] * (1 - answer.count(elem1)) + [elem2] * (1 - answer.count(elem2))
    answer += [2] * (n - len(answer))
    #answer = answer[:n]
    output.write(''.join(map(str, answer)))
    output.write('\n')
output.close()