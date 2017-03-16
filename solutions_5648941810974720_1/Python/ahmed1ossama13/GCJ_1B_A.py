fin = open("/home/ahmed/Desktop/GCJ_1B/A-large.in", "r")
fout = open("/home/ahmed/Desktop/GCJ_1B/A-large.out", "w")
L = {}
H = []
L["ZERO"] = 'Z'
L["SIX"] = 'X'
L["EIGHT"] = 'G'
L["TWO"] = 'W'
L["THREE"] = 'T'
L["FOUR"] = 'R'
L["ONE"] = 'O'
L["FIVE"] = 'F'
L["SEVEN"] = 'V'
L["NINE"] = 'E'
H = ["ZERO", "SIX", "EIGHT", "TWO", "THREE", "FOUR", "ONE", "FIVE", "SEVEN", "NINE"]
M = [0, 6, 8,2,3,4,1,5,7,9]
T = int(fin.readline())
res = ""
case = 1
while (T > 0):
    T -= 1
    s = list(fin.readline().split()[0])
    ans = []
    for i in range(len(H)):
        letter = H[i]
        x = L[letter]
        while (x in s):
            for char in letter:
                s.remove(char)
            ans.append(M[i])
    ans.sort()
    
    res += "Case #" + str(case) + ": "
    case += 1
    for item in ans:
        res += str(item)
    res += "\n"
fout.write(res)
fout.close()
