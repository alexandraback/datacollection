import re

def check_game(lawn):
    row_maxes = [max(x) for x in lawn]
    cols = [[lawn[i][j] for i in range(len(lawn))] for j in range(len(lawn[0]))]
    col_maxes = [max(x) for x in cols]
    for i in range(len(lawn)):
        for j in range(len(lawn[i])):
            val = lawn[i][j]
            if val != row_maxes[i] and val != col_maxes[j]:
                return "NO"
    return "YES"
        

def read_game(f):
    dims = re.split(" ",f.readline())
    x,y = int(dims[1]), int(dims[0])    
    lawn = []
    for i in range(y):
        line = f.readline()
        nums = [int(x.strip()) for x in re.split(" ",line)]
        lawn.append(nums)
    return lawn

def main():
    output = []
    with open("B-large.in","r") as f:
        trials = f.readline()
        for i in range(int(trials.strip())):
            state = read_game(f)
            outline = "Case #%d: %s" % (i+1, check_game(state))
            print (outline)
            output.append(outline)
    with open("lawn.out","w") as f:
        f.write("\n".join(output))


if __name__ == "__main__":
    main()
