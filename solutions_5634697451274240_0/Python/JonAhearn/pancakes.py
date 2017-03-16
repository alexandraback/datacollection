T = int(input())

for test in range(T):
    stack = input()
    flips = 0
    last_char = '?'
    for char in stack:
        if last_char != '?' and char != last_char:
            flips += 1
        last_char = char
    if last_char == '-':
        flips += 1
    print('Case #' + str(test+1) + ': ' + str(flips))