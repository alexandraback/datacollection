import re, sys

pattern = "OOOO|O....O....O....O|O.....O.....O.....O|O...O...O...O"
checkO = re.compile(pattern, re.S)
checkX = re.compile(pattern.replace("O","X"), re.S)

def solve_with_regex(lines):
    #set T to O and test with the O-regex
    if checkO.search(lines.replace("T", "O")):
        return "O won"
    #set T to X and test with the X-regex
    if checkX.search(lines.replace("T", "X")):
        return "X won"
    if lines.find(".")!=-1:
        return "Game has not completed"
    return "Draw"

def solve_with_bits(lines):
    mapping = {".":0, "O": 1, "X":2, "T":3}
    m = 0
    for c in lines:
        if mapping.has_key(c):
            m = (m<<2)+mapping[c]
    
    pat = [(4, 0x55, 1, 7),       # 4x, horicontal, 1 bit for O, 8 bit next test
           (4, 0x01010101, 1, 1), # 4x, vert. line, next Vert. only 1 bit 
           (1, 0x01041040, 1, 1), # 1x, /, 1 bit shift
           (1, 0x40100401, 1, 1)  # 1x, \, 1 bit shift
          ]
    
    for loop, hBits, shift1, shift2 in pat:
        for i in range(loop):
            if m & hBits == hBits:
                return "O won"
            hBits = hBits << shift1              # 1 bit shift for X
            if m & hBits == hBits:
                return "X won"
            hBits = hBits << shift2             # next line

    #no winner, search for free dot -> not completed"
    if lines.find(".")!=-1:
        return "Game has not completed"
    return "Draw"

IN = file(sys.argv[1])

for t in range(1, int(IN.readline())+1):
    
    lines = "".join([IN.readline() for x in range(5)])
    print "Case #%d: %s" % (t, solve_with_regex(lines))
