n = int(input())

for test in range(n):
    Z = 0
    O = 0
    W = 0
    H = 0
    U = 0
    F = 0
    X = 0
    V = 0
    G = 0
    I = 0
    string = input()
    for char in string:
        if char == 'Z':
            Z+=1
        if char == 'O':
            O+=1
        if char == 'W':
            W+=1
        if char == 'H':
            H+=1
        if char == 'U':
            U+=1
        if char == 'F':
            F+=1
        if char == 'X':
            X+=1
        if char == 'V':
            V+=1
        if char == 'G':
            G+=1
        if char == 'I':
            I+=1
    zero = Z
    two = W
    four = U
    six = X
    eight = G
    three = H - eight
    five = F - four
    seven = V - five
    one = O - zero - two - four
    nine = I - five - six - eight
    
    answer = '0'*zero + '1'*one + '2'*two + '3'*three + '4'*four + '5'*five + '6'*six + '7'*seven + '8'*eight + '9'*nine
    print('Case #' + str(test+1) + ': ' + answer)