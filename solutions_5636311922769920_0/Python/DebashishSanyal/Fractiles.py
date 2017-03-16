result = ""
t = int(raw_input())
for i in range(1, t + 1):
    K, C, S = [int(s) for s in raw_input().split(" ")]
    checklist = []
    if S == K:
        result_temp = ""
        pos = 1
        jump = K**(C-1)
        for j in xrange(0,K):
            result_temp = result_temp + " " + str(pos)
            pos +=  jump
    elif S < K:
        result_temp = "IMPOSSIBLE"
    result = result + "Case #{}: {}\n".format(i,result_temp)


print result
file_name = "output.txt"
text_file = open(file_name, "w")
text_file.write(result)

#for i in xrange(50)
