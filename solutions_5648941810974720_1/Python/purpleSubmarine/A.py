t = int(raw_input())

for p in xrange(1, t + 1):
    s = raw_input()
    arr = {}
    for i in range(26):
        arr[chr(65 + i)] = 0
    #for i in range(25):
     #   arr.append(0)
    for letter in s:
        #x = ord(letter) - 65
        arr[letter] += 1
    ans = []
    # 0
    for i in range(10):
        ans.append(0)
    ans[0] = arr['Z']
    arr['E'] -= arr['Z']
    arr['R'] -= arr['Z']
    arr['O'] -= arr['Z']
    arr['Z'] = 0
    ans[6] = arr['X']
    arr['S'] -= ans[6]
    arr['I'] -= ans[6]
    arr['X'] = 0
    ans[2] = arr['W']
    arr['T'] -= ans[2]
    arr['O'] -= ans[2]
    arr['W'] = 0
    ans[7] = arr['S']
    arr['S'] -= ans[7]
    arr['E'] -= 2 * ans[7]
    arr['N'] -= ans[7]
    arr['V'] -= ans[7]
    ans[8] = arr['G']
    arr['E'] -= ans[8]
    arr['I'] -= ans[8]
    arr['H'] -= ans[8]
    arr['T'] -= ans[8]
    arr['G'] = 0
    ans[3] = arr['H']
    arr['T'] -= ans[3]
    arr['H'] -= ans[3]
    arr['R'] -= ans[3]
    arr['E'] -= ans[3] * 2
    ans[5] = arr['V']
    arr['F'] -= ans[5]
    arr['I'] -= ans[5]
    arr['V'] -= ans[5]
    arr['E'] -= ans[5]
    ans[4] = arr['F']
    arr['F'] -= ans[4]
    arr['O'] -= ans[4]
    arr['U'] -= ans[4]
    arr['R'] -= ans[4]
    ans[1] = arr['O']
    arr['O'] -= ans[1]
    arr['N'] -= ans[1]
    arr['E'] -= ans[1]
    ans[9] = arr['I']
    ans_s = ''
    for i in range(10):
        for j in range(ans[i]):
            ans_s += str(i)  
    
    print "Case #{}:".format(p),
    print ans_s