f = open('Input.txt')
lines = f.readlines()
f.close()

output = open('Rnd2AOutput.txt','w')
ctr = 0

for i in range(int(lines[0])):
    N = int(lines[ctr+1])
    ctr += 1
    lists = []
    d = {}
    for j in range(2*N-1):
        l = lines[ctr+1].strip().split()
        new_l = []
        for let in l:
            new_l.append(int(let))
        for num in new_l:
            if num in d.keys():
                d[num] += 1
            else:
                d[num] = 1

        #lists.append(lines[ctr+1].split())

        ctr += 1

    missing_list = []
    for key in d:
        if d[key] % 2:
            missing_list.append(key)
    missing_list.sort()
    missing_list = missing_list

    result = ""
    for num in missing_list:
        result += str(num) + " "
    result = result.strip()
    output.write("Case #" + str(i+1) + ": " + result + "\n")
output.close() 