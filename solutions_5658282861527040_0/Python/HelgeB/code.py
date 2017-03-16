file = open('B-small-attempt0.in', 'r')
output = open('output', 'w')

T = file.readline()

for x in range(1, int(T)+1):
    [A, B, K] = list(map(lambda x: int(x), file.readline().replace('\n', '').split(' ')))
    
    
    sum = 0
    for a in range(A):
        for b in range(B):
            if a&b < K:
                sum = sum + 1
         
    solution = 'Case #' + str(x) + ': ' + str(sum) + '\n'
    if x == int(T):
        solution.replace('\n', '')
    output.write(solution)
    print(solution)