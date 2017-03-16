f = open('Input.txt')
lines = f.readlines()
f.close()

output = open('Rnd1AOutput.txt','w')
for i in range(int(lines[0])):
    S = lines[i+1].strip()
    first_letter = S[0]

    inter = first_letter
    for j in range(len(S)):
        if j != 0:
            if S[j] >= inter[0]:
                inter = S[j] + inter
            else:
                inter = inter + S[j]

    #inter = ''.join(sorted(S))
    result = inter
    output.write("Case #" + str(i+1) + ": " + result + "\n")
output.close() 