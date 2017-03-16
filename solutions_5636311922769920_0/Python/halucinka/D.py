T = int(input())

for i in range(1, T+1):
    line = input().split(' ')
    K = int(line[0])
    C = int(line[1])
    S = int(line[2])
    print("Case #"+str(i) + ":", end = '')
    for j in range(1, S+1):
        print(' ' + str(j), end = '')
    print()
