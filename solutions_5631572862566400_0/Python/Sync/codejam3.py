def readFile (filename):
    result = []
    with open(filename, "r") as f:
        for line in f:
            line = line.split()
            result.append(line)
    return result

def countem(BFFs):
    taken = []
    total = 0
    for i in range(0, len(BFFs)):
        if i+1 not in taken:
            taken.append(i+1)
            total += 1
            if int(BFFs[i]) not in taken:
                taken.append(int(BFFs[i]))
    return total
    
        

def main():
    file = "file.txt"
    data = readFile(file)
    count = 1
    for i in range(2, len(data), 2):
        print("Case #{0}: {1}".format(count, countem(data[i])))
        count += 1

