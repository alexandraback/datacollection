def solve(in_file, out_file):
    trials=int(in_file.readline())
    for trial in range(1, trials + 1):
        sol = ""
        heights = [0] * 2501
        size = int(in_file.readline())
        for _ in range(2*size-1):
            raw_list = in_file.readline()
            raw_list = raw_list.strip()
            raw_list = raw_list.split()
            cur_list = [int(num) for num in raw_list]
            #print(cur_list)
            for height in cur_list:
                heights[height] += 1
        #print(heights)
        for index, height in enumerate(heights):
            if height%2 ==1:
                sol += "{} ".format(index)
        out_file.write("Case #{}: {}\n".format(trial, sol.strip()))

if __name__ == '__main__':
    path='Data\\'
    #name='B-sample'
    name='B-small-attempt0'
    #name='B-large'
    raw=open(path+name+'.in', 'r')
    wrt=open(path+name+'.out','w')
    solve(raw, wrt)
    raw.close()
    wrt.close()