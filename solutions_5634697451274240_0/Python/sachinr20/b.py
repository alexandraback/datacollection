import sys

def flip(st, count):
    #if count==len(st):
    #    return st[::-1]
    l = count
    st2 = ""
    for i in range(count):
        if st[i]=='+':
            st2 = st2 + "-"
        else:
            st2 = st2 + "+"
    #print("st2new:"+st2)
    st2 = st2[::-1]
    return st2+st[count:]

def handleit(line, count):
    #print("Handling "+line + " len:"+ str(len(line)))
    chars = [x for x in line]
    if len(line)<=0:
        return count;
    if len(line) == 1:
        if chars[0]=='+':
            return count;
        else:
            count = count + 1
            return count

    total = len(line)
    if line[total-1] == '+':
        return handleit(line[:-1], count)
    else:
        pluses = 0
        for ch in chars:
            if ch != '+':
                break
            pluses += 1
        if pluses == 0:
            line = flip(line, len(line))
            count +=1
        else:
            line = flip(line, pluses)
            line = flip(line, len(line))
            count += 2
        return handleit(line[:len(line)-pluses], count)


name = sys.argv[1]

with open(name) as f:
    lines = f.readlines()
lines = lines[1:]


case = 0

with open("out", "w") as o:
    for line in lines:
        case += 1
        line = line.strip()
        count = 0
        c = handleit(line, count)
        op = "Case #"+str(case)+": "+str(c)+"\n"
        print(op, end="")
        o.write(op)

