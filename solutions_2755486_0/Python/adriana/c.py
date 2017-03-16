input_file = 'C-small-attempt0.in'
output_file = 'output.txt'

f = open(input_file, 'r')
out = open(output_file, 'w')

def solve(test, attacks):
    wall = {}
    succ = 0
    days = sorted(attacks.keys())
    for d in days:
        d_att = attacks[d]
        if len(d_att) == 1:
            marked = 0
            w = d_att[0][0]
            e = d_att[0][1]
            s = d_att[0][2]
            for x in range(w, e):
                if x in wall:
                    if wall[x]<s:
                        if marked == 0:
                            succ += 1
                            marked = 1
                        wall[x] = s
                else:
                    if s > 0:
                        if marked == 0:
                                succ += 1
                                marked = 1
                        wall[x] = s
                            
        else:
            temp_wall = {}
            for l in d_att:
                w = l[0]
                e = l[1]
                s = l[2]
                marked = 0
                for x in range(w, e):
                    if x in wall:
                        if wall[x]<s:
                            if marked == 0:
                                succ += 1
                                marked = 1
                            if x in temp_wall:
                                if s > temp_wall[x]:
                                    temp_wall[x] = s
                            else:
                                temp_wall[x] = s
                    else:
                        if s > 0:
                            if marked == 0:
                                succ += 1
                                marked = 1
                            if x in temp_wall:
                                if s > temp_wall[x]:
                                    temp_wall[x] = s
                            else:
                                temp_wall[x] = s
              
            # copy from temp to wall:
            temp_keys = temp_wall.keys()
            for k in temp_keys:
                wall[k] = temp_wall[k]
    out.write("Case #" + str(test) + ": " + str(succ) + "\n") 
                
#read no test cases:
no_tests = int(f.readline())

for test in range(0, no_tests):
    N = int(f.readline())
    attacks = {}
    print "test no", str(test)
    for i in range(0, N):
        tribe = f.readline()
        d,n,w,e,s,dd,dp,ds = map(int, tribe.split())
        for day in range(0, n):
            crt_day = d + day * dd
            if crt_day in attacks:
                attacks[crt_day].append([w+day*dp, e+day*dp, s+day*ds])
            else:
                attacks[crt_day] = []
                attacks[crt_day].append([w+day*dp, e+day*dp, s+day*ds])
    solve(test+1, attacks)
    
f.close()
out.close()
