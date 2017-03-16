binary = ""
B = 0
def run(line):
    global binary, B
    B = int(line.split()[0])
    M = int(line.split()[1])
    if M > pow(2,B-2):
        return False
    elif M == pow(2,B-2):
        binary = ("{0:0" + str(B-1) + "b}").format(M-1) + "1"
        return True
    else:
        binary = ("{0:0" + str(B-1) + "b}").format(M) + "0"
        return True

fi = open("B-small-attempt0.in", "r")
fo = open("output_b.txt", "w")
templines = fi.readlines()
T = int(templines[0])
for i in range(T):
    answer = run(templines[i+1])
    if answer == False:
        fo.write("Case #" + str(i+1) + ": " + "IMPOSSIBLE\n")
    else:
        fo.write("Case #" + str(i+1) + ": " + "POSSIBLE\n")
        fo.write(binary + "\n")
        for j in range(B-1):
            fo.write("0" * (j+2) + "1" * (B-j-2) + "\n")
fi.close()
fo.close()
