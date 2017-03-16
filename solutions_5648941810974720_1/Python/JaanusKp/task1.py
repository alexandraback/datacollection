fin = open("in1.txt", "r")
fout = open("out1.txt", "w")

T = int(fin.readline().strip())
for x in xrange(T):
    line = fin.readline().strip()
    chars = {'Z': 0, 'E': 0, 'R': 0, 'O': 0, 'N': 0, 'T': 0, 'W': 0, 'H': 0, 'F': 0, 'U': 0, 'I': 0, 'V': 0, 'S': 0, 'X': 0, 'G': 0}
    result = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    for c in line:
        chars[c] += 1
    result[0] = chars['Z']
    result[2] = chars['W']
    result[4] = chars['U']
    result[6] = chars['X']
    result[8] = chars['G']
    result[3] = chars['H'] - result[8]
    result[1] = chars['O'] - result[0] - result[2] - result[4]
    result[5] = chars['F'] - result[4]
    result[7] = chars['V'] - result[5]
    result[9] = (chars['N'] - result[1] - result[7])/2
    print chars
    print(result)
    fout.write("Case #%d: " % (x+1))
    for y in xrange(10):
        fout.write(chr(ord('0')+y) * result[y])
    fout.write("\n")

fin.close()
fout.close()