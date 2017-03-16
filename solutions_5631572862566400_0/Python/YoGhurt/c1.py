def max_length_from(inputs, outputs, k, visited, ):
    print "K: {}".format(k)
    print "VISIT: {}".format(visited)
    l = 1
    nextelement = outputs[k]
    if nextelement in visited and visited[0] != nextelement and visited[-1] != nextelement:
        print "ERR RET 0"
        return 0
    addition = 0
    new_visited = list(visited)
    new_visited.append(k)
    if nextelement not in visited:
        addition = max_length_from(inputs, outputs, nextelement, new_visited)
        if addition == 0 and len(visited) > 0 and visited[-1] != nextelement:
            print "ERR RET 0"
            return 0
    if k in inputs.keys() and len(visited) > 0 and visited[-1] == nextelement:
        for element in inputs[k]:
            if element not in visited:
                p = max_length_from(inputs, outputs, element, new_visited)
                if p > addition:
                    addition = p
    print "ADD: {}".format(addition)
    return l + addition

def longest_path(inputs, outputs):
    print inputs
    print outputs
    maxlength = 0
    for k in outputs.keys():
        l = max_length_from(inputs, outputs, k, [])
        print "K: {}, L: {}".format(k, l)
        if maxlength < l:
            maxlength = l
    return maxlength

def solve(N, bfflist, x, res):
    bfflist = bfflist.split()
    inputs = {}
    outputs = {}
    i = 1
    for bff in bfflist:
        ibff = int(bff)
        outputs[i] = ibff
        if ibff not in inputs.keys():
            inputs[ibff] = []
        inputs[ibff].append(i)
        i += 1
    lp = longest_path(inputs, outputs)
    res.write("Case #{}: {}\n".format((x+1), lp))

def main():
    f = open("C://CodeJam/c2.in", 'r')
    res = open("C://CodeJam/c2.out", 'w')
    T = int(f.readline())
    for x in range(T):
        N = int(f.readline())
        bfflist = f.readline()
        solve(N, bfflist, x, res)
    f.close()
    res.close()

if __name__ == "__main__":
    main()
