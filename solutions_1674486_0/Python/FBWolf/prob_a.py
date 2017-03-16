
map = {}
visited = {}
global_visited = {}

def dfs(index, n):
    if index in visited:
        return True
    visited[index] = True
    global_visited[index] = True
    
    for nexti in map[index]:
        res = dfs(nexti, n)
        if res:
            return True
        
    return False

if __name__ == "__main__":
    in_f = open("A-small-attempt1.in", "r")
    out_f = open("A.output", "w")
    nowcase = 0
    line = in_f.readline()
    ncase = int(line.strip())
    
    for nowcase in range(ncase):
        line = in_f.readline().strip()
        n = int(line)
        map = {}
        for i in range(n):
            line = in_f.readline().strip()
            parts = line.split()
            map[i] = []
            for part in parts[1:]:
                map[i].append(int(part) - 1)
        
        global_visited = {}
        res = False
        for i in range(n):
            if i not in global_visited:
                visited = {}
                tmp_res = dfs(i, n)
                if tmp_res:
                    res = True
                    break
        
        outline = "Case #%s: %s\n" % (nowcase + 1, "Yes" if res else "No")
        out_f.write(outline)
    in_f.close()
    out_f.close()
    