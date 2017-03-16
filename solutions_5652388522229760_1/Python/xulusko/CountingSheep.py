from sys import stdin

data = stdin.readlines()

for case, line in enumerate(data[1:], 1):
    N = int(line)
    if (N == 0):
        answer = 'INSOMNIA'
    else:
        seenDigits = set(list(str(N)))
        currentNum = N
        #max 100 iterations - round N to next pow of 10 and check biggest digits
        while (len(seenDigits) < 10):
            currentNum += N
            seenDigits.update(list(str(currentNum)))
        answer = currentNum
    print('Case #{}: {}'.format(case, answer))
