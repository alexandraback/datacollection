def readFile (filename):
    result = []
    with open(filename, "r") as f:
        for line in f:
            line = line.split()
            result.append(line)
    return result

def lastWord (word):
    result = word[0]
    for i in word[1:]:
        if i < result[0]:
            result = result + i
        else:
            result = i + result
    return result

def main():
    file = "file.txt"
    data = readFile(file)
    for i in range(1, len(data)):
        print("Case #{0}: {1}".format(i, lastWord(data[i][0])))
