import itertools

def solve(in_file, out_file):
    trials=int(in_file.readline())
    for trial in range(1, trials + 1):
        special_paths = dict()
        N = int(in_file.readline())
        bffs = [int(word) for word in in_file.readline().strip().split()]
        best = 0
        for kid in range(1, N+1):
            path = [kid]
            cur_kid = kid
            next_kid = bffs[kid - 1]
            while next_kid not in path:#visited:
                cur_kid, next_kid = next_kid, bffs[next_kid - 1]
                path.append(cur_kid)
            last_kid = next_kid
            circle = 0
            for index, path_kid in enumerate(path):
                if path_kid == last_kid:
                    if index == len(path) - 2:
                        last = tuple(path[-2:])
                        if last in special_paths:
                            special_paths[last].append(path)
                        else:
                            special_paths[last]=[path]
                        circle = len(path)
                    else:
                        circle = len(path) - index
                    break
                
            if circle > best:
                best = circle
        largest_size = dict()
        for last in special_paths:
            max_path = []
            for path in special_paths[last]:
                if len(path) > len(max_path):
                    max_path = path
            largest_size[last] = len(max_path)
        pairs = (tuple(sorted(last)) for last in largest_size)
        total = 0
        for pair in pairs:
            rev = (pair[1], pair[0])
            if pair in largest_size:
                total += largest_size[pair]
                if rev in largest_size:
                    total += largest_size[rev] - 2
            else:
                if rev in largest_size:
                    total += largest_size[rev]
        if total/2 > best:
            best = int(total/2)         
        out_file.write("Case #{}: {}\n".format(trial, best))

if __name__ == '__main__':
    path='Data\\'
    #name='C-sample'
    #name='C-small-attempt1'
    name='C-large'
    raw=open(path+name+'.in', 'r')
    wrt=open(path+name+'.out','w')
    solve(raw, wrt)
    raw.close()
    wrt.close()