#!/usr/bin/python3

mult = {
    '11': '1',
    'i1': 'i',
    'j1': 'j',
    'k1': 'k',
    '1i': 'i',
    'ii': '-1',
    'ji': '-k',
    'ki': 'j',
    '1j': 'j',
    'ij': 'k',
    'jj': '-1',
    'kj': '-i',
    '1k': 'k',
    'ik': '-j',
    'jk': 'i',
    'kk': '-1'
}
    
line = input()
T = int(line)

for run in range(1, T + 1):
    line = input()
    L, X = map(int, line.split(' '))

    S = input()

    A = ""
    B = ""

    flag = False

    sign = 1
    current = '1'

    cutoff = -1
    search_string = S * min(X, 5)

    # searching for 'i'
    for idx, c in enumerate(search_string):
        current = mult[current + c]
        if current[0] is '-':
            sign *= -1
            current = current[1:]

        if current is 'i' and sign is 1:
            cutoff = idx // L
            A = S[(idx % L) + 1:]
            X -= (cutoff + 1)
            # print('i = ' + search_string[:idx + 1])
            break

    if cutoff < 0:
        flag = True
    else:
        # print("A = " + A)
        # searching for 'j'
        cutoff = -1

        sign = 1
        current = '1'
        search_string = A + (S * min(X, 5))

        for idx, c in enumerate(search_string):
            current = mult[current + c]
            if current[0] is '-':
                sign *= -1
                current = current[1:]

            if current is 'j' and sign is 1:
                # print('j = ' + search_string[:idx + 1])
                if idx < len(A):
                    B = A[(idx + 1):]
                    cutoff = 0
                else:
                    cutoff = (idx - len(A)) // L
                    B = S[((idx - len(A)) % L) + 1:]
                    X -= (cutoff + 1)
                break

    if cutoff < 0:
        flag = True
    else:
        # searching for 'k'
        cutoff = -1

        sign = 1
        current = '1'
        # print("X = " + str(X))
        # print("B = " + B)

        # want to check if B L^X = k <=> B 
        search_string = B + S * (X % 4)

        for idx, c in enumerate(search_string):
            current = mult[current + c]
            if current[0] is '-':
                sign *= -1
                current = current[1:]

        if not (current is 'k' and sign is 1):
            flag = True
        
    if flag:
        print("Case #%i: %s" % (run, 'NO'))
    else:
        print("Case #%i: %s" % (run, 'YES'))
