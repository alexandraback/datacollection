from collections import defaultdict


inputs = int(raw_input())

for qqq in range(inputs):
    inp = raw_input()
    hash = {}
    hash = defaultdict(lambda: 0, hash)

    for ch in inp:
        hash[ch] += 1

    h = hash
    
    ls = [h['Z'], h['O'] - h['W'] - h['U'] - h['Z'], h['W'], h['H'] - h['G'], h['U'], h['F'] - h['U'], h['X'], h['S'] - h['X'], h['G'], h['I'] - h['G'] - h['X'] - h['F'] + h['U']]

    out = ""
    for i in range(len(ls)):
        for j in range(ls[i]):
            out = out + str(i)
        
    print "Case #" + str(qqq+1) + ": " + out
    
    
