#f = open('a_in.txt','r')
#s = open('a_sample.txt','r')
#t = int(f.readline())
#lines = f.readlines()
#sample = s.readlines()
#table = {}
#for i in range(t):
#    for j in range(len(sample[i])):
#        table[lines[i][j]] = sample[i][j]
##for i in range(ord('a'),ord('z')+1):
##    if not chr(i) in table:
##        print chr(i)
#table['z']='q'
#table['q']='z'
#print table

table = {'\n': '\n', ' ': ' ', 'a': 'y', 'c': 'e', 'b': 'h', 'e': 'o', 'd': 's', 'g': 'v', 'f': 'c', 'i': 'd', 'h': 'x',
         'k': 'i', 'j': 'u', 'm': 'l', 'l': 'g', 'o': 'k', 'n': 'b', 'q': 'z', 'p': 'r', 's': 'n', 'r': 't', 'u': 'j',
         't': 'w', 'w': 'f', 'v': 'p', 'y': 'a', 'x': 'm', 'z': 'q'}

f = open('A-small-attempt0.in', 'r')
o = open('a1_out.txt', 'w')
t = int(f.readline())
lines = f.readlines()
for i in range(t):
    o.write('Case #' + str(i + 1) + ': ')
    for j in range(len(lines[i])):
        o.write(table[lines[i][j]])

f.close()
o.close()
