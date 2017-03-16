# Google Code Jam 2016 Round 1C
# Problem B. Slides!

# There are no cycles.

# 2 : 1 -> 2. (M = 1)
# 3 : 1 -> 3. (M = 1), 1 -> 2 -> 3, 1 -> 3 (M = 2).
# 4 : 1 -> 4. (M = 1), 1 -> 3 -> 4, 1 -> 4 (M = 2).
# 1 -> 2 -> 4, 1 -> 3 -> 4, 1 -> 4 (M = 3).
# 1 -> 2 -> 3 -> 4, 1 -> 2 -> 4, 1 -> 3 -> 4, 1 -> 4 (M = 4).
# 5 : 1 -> 2 -> 5, 1 -> 3 -> 4 -> 5, 1 -> 3 -> 5, 1 -> 4 -> 5, 1 -> 5, 1 -> 2 -> 4 -> 5.

# 1 -> 2 -> 3 -> 4 -> 5
# 1 -> 2 -> 3 -> 5

# If M <= 2**(B - 3), we can simply ignore position 2. I don't know what to do otherwise.

# Otherwise, have 1 map to everything that 2 maps to. This doubles the result. If necessary, add or remove a slide from 1 to 5.

# B = 6: We only need M = 8, 10, 13, 15, 16.

# There are more slides than I initially thought because you can use a slide to go to a smaller number. I no longer know what the maximum is. This shouldn't be different from what I'm doing since it's still just ensuring that there are no cycles.

def slides(B, M):
    if M > 2**(B - 2):
        return False
    if B == 2:
        return ['01', '00']
    if B == 3:
        if M == 1:
            return ['001', '000', '000']
        return ['011', '001', '000']
    if B == 4:
        if M == 1:
            return ['0001', '0000', '0000', '0000']
        if M == 2:
            return ['0011', '0000', '0001', '0000']
        if M == 3:
            return ['0111', '0001', '0001', '0000']
        return ['0111', '0011', '0001', '0000']
    if B == 5:
        if M == 1:
            return ['00001', '00000', '00000', '00000', '00000']
        if M == 2:
            return ['00011', '00000', '00000', '00001', '00000']
        if M == 3:
            return ['00111', '00000', '00001', '00001', '00000']
        if M == 4:
            return ['00111', '00000', '00011', '00001', '00000']
        if M == 5:
            return ['01111', '00001', '00011', '00001', '00000']
        if M == 6:
            return ['01111', '00011', '00011', '00001', '00000']
        if M == 7:
            return ['01110', '00111', '00011', '00001', '00000']
        return ['01111', '00111', '00011', '00001', '00000']
    else:
        if M == 1:
            return ['000001', '000000', '000000', '000000', '000000', '000000']
        if M == 2:
            return ['000011', '000000', '000000', '000000', '000001', '000000']
        if M == 3:
            return ['000111', '000000', '000000', '000001', '000001', '000000']
        if M == 4:
            return ['000111', '000000', '000000', '000011', '000001', '000000']
        if M == 5:
            return ['001111', '000000', '000001', '000011', '000001', '000000']
        if M == 6:
            return ['001111', '000000', '000011', '000011', '000001', '000000']
        if M == 7:
            return ['001110', '000000', '000111', '000011', '000001', '000000']
        if M == 8:
            return ['010000', '001111', '000111', '000011', '000001', '000000']
        if M == 9:
            return ['010001', '001111', '000111', '000011', '000001', '000000']
        if M == 10:
            return ['010100', '001111', '000111', '000011', '000001', '000000']
        if M == 11:
            return ['010110', '001111', '000111', '000011', '000001', '000000']
        if M == 12:
            return ['011000', '001111', '000111', '000011', '000001', '000000']
        if M == 13:
            return ['011010', '001111', '000111', '000011', '000001', '000000']
        if M == 14:
            return ['011100', '001111', '000111', '000011', '000001', '000000']
        if M == 15:
            return ['011110', '001111', '000111', '000011', '000001', '000000']
        else:
            return ['011111', '001111', '000111', '000011', '000001', '000000']

# slides(5, 4) -> slides(4, 2) -> slides(3, 1).

def slides(B, M):
    if M > 2**(B - 2):
        return False
    if B == 2:
        return ['01', '00']
    if M%2 == 0:
        result = ['0' + i for i in slides(B - 1, M/2)]
        first = '01' + result[0][2:]
        return [first] + result
    result = ['0' + i for i in slides(B - 1, M/2 + 1)]
    if result[0][-1] == '1':
        first = '01' + result[0][2:-1] + '0'
        return [first] + result
    result = ['0' + i for i in slides(B - 1, M/2)]
    first = '01' + result[0][2:-1] + '1'
    return [first] + result

# (B, M) = (3, 1).

# Problem with (4, 1). Comes from slides(4, 0) or slides(4, 2). But, slides(4, 2) has no slide from 1 to 4.

def slides(B, M):
    if M == 0 or M > 2**(B - 2):
        return False
    if M == 1:
        return [(B - 1)*'0' + '1'] + (B - 1)*[B*'0']
    if B == 2:
        return ['01', '00']
    if M%2 == 0:
        result = ['0' + i for i in slides(B - 1, M/2)]
        first = '01' + result[0][2:]
        return [first] + result
    smaller = slides(B, M - 1)
    if smaller != False and smaller[0][-1] == '0':
        # Add slide.
        return [smaller[0][:-1] + '1'] + smaller[1:]
    larger = slides(B, M + 1)
    if larger[0][-1] == '1':
        print B, M
        return [larger[0][:-1] + '0'] + larger[1:]
    print B, M, '?????'

def paths():
    f = open('commands.txt', 'r')
    g = open('slides.txt', 'w')
    line = 0
    for i in f:
        if line == 0:
            T = int(i)
            line += 1
        else:
            B = ''
            M = ''
            spaces = 0
            for j in i:
                if j == ' ':
                    spaces = 1
                    B = int(B)
                elif j == '\n':
                    M = int(M)
                else:
                    if spaces == 0:
                        B += j
                    else:
                        M += j
            g.write('Case #' + str(line) + ': ')
            print line
            result = slides(B, M)
            if result == False:
                g.write('IMPOSSIBLE\n')
            else:
                g.write('POSSIBLE\n')
                for i in result[:-1]:
                    g.write(i + '\n')
                g.write(result[-1] + (T != line)*'\n')
            line += 1
    f.close()
    g.close()
