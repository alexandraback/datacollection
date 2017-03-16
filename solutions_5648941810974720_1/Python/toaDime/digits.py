def main_code(x):
    string = input()
    counts = dict()
    for c in "ZEROONETWOTHREEFOURFIVESIXSEVENEIGHTNINE":
        counts[c] = 0
    for c in string:
        counts[c] += 1
            
    result = []
    
    num = counts['Z']
    if num > 0:
        result += ['0']*num
        for c in 'ZERO':
            counts[c] -= num
            
    num = counts['W']
    if num > 0:
        result += ['2']*num
        for c in 'TWO':
            counts[c] -= num
        
    num = counts['U']
    if num > 0:
        result += ['4']*num
        for c in 'FOUR':
            counts[c] -= num
    
    num = counts['X']
    if num > 0:
        result += ['6']*num
        for c in 'SIX':
            counts[c] -= num
        
    num = counts['G']
    if num > 0:
        result += ['8']*num
        for c in 'EIGHT':
            counts[c] -= num
        
    num = counts['R']
    if num > 0:
        result += ['3']*num
        for c in 'THREE':
            counts[c] -= num
            
    num = counts['O']
    if num > 0:
        result += ['1']*num
        for c in 'ONE':
            counts[c] -= num
            
    num = counts['F']
    if num > 0:
        result += ['5']*num
        for c in 'FIVE':
            counts[c] -= num
            
    num = counts['S']
    if num > 0:
        result += ['7']*num
        for c in 'SEVEN':
            counts[c] -= num
            
    num = counts['I']
    if num > 0:
        result += ['9']*num
        for c in 'NINE':
            counts[c] -= num
            
    result.sort()
    print("Case #" + str(x + 1) + ":", "".join(result))

T = int(input())
for x in range(T):
    main_code(x)
