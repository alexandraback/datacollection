#!/usr/bin/python3

def build_outfit(JJ, SS, PP, KK, case_id):
    #if (JJ >= KK):
        #JJ = KK
        #total = JJ * PP * SS
        #print("Case #" + str(case_id+1) + ": " + str(total))
        #pp = 0
        #ss = 0
        #for PP in range(PP):
        #for jj in range(JJ):
            #print(str(jj+1) + " " + str(pp+1) + " " + str(ss+1))
            #pp += 1
            #ss += 1
    #elif (PP >= KK):
        #PP = KK
        #total = JJ * PP * SS
        #print("Case #" + str(case_id+1) + ": " + str(total))
        #ss = 0
        #jj = 0
        #for pp in range(PP):
            #print(str(jj+1) + " " + str(pp+1) + " " + str(ss+1))
            #ss += 1
            #jj += 1
    #elif (SS >= KK):
        #SS = KK
        #total = JJ * PP * SS
        #print("Case #" + str(case_id+1) + ": " + str(total))
        #pp = 0
        #jj = 0
        #for ss in range(SS):
            #print(str(jj+1) + " " + str(pp+1) + " " + str(ss+1))
            #pp += 1
            #jj += 1
    #else:
        #total = JJ * PP * SS
        #print("Case #" + str(case_id+1) + ": " + str(total))
        #for jj in range(JJ):
            #for pp in range(PP):
                #for ss in range(SS):
                    #print(str(jj+1) + " " + str(pp+1) + " " + str(ss+1))
    #if (KK == 1): # Special case
        #total = JJ + 
    #if (JJ >= KK):
        #JJ = KK
    #elif (PP >= KK):
        #PP = KK
    #elif (SS >= KK):
        #SS = KK
    SS = min(SS, KK)
    total = JJ * PP * SS
    print("Case #" + str(case_id+1) + ": " + str(total))
    for jj in range(JJ):
        for pp in range(PP):
            for ss in range(SS):
                print(str(jj+1) + " " + str(pp+1) + " " + str(ss+1))
    return

TT = int(input())
for ii in range(TT):
    JJ, PP, SS, KK = (int(_) for _ in input().split(" "))
    build_outfit(JJ, SS, PP, KK, ii)

