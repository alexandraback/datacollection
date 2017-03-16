f = [line.rstrip() for line in open('/Users/roshil/Desktop/A-small-attempt0 (2).in')]
out = open('/Users/roshil/Desktop/out.txt','w')
out.truncate()
line = 0
testcases = int(f[line])
line += 1
letters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
dic = {}
for index,letter in enumerate(letters):
    dic[letter] = index
for i in range(1,testcases+1):
    word = f[line]
    line += 1
    ans = word[0]
    for let in word[1:]:
        if dic[let] < dic[ans[0]]:
            ans += let
        else:
            ans = let+ ans
    print ans
    out.write("Case #"+str(i)+": "+ str(ans) + "\n")
out.close()