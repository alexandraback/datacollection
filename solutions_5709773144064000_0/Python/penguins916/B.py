f = open("B.in")
num = int(f.readline())
output = ""
for n in range(num):
    C, F, X = [float(x) for x in f.readline().strip().split(" ")]
    cur_time = 0
    cur_farms = 0
    
    output_val = 0
    while True:
        stay_time = X / (cur_farms * F + 2)
        time_to_farm = C / (cur_farms * F + 2)
        time_with_farm = time_to_farm + X / ((cur_farms + 1) * F + 2)

        if stay_time < time_with_farm:
            output_val = stay_time + cur_time
            break
        else:
            cur_time = time_to_farm + cur_time
            cur_farms += 1

    output += "Case #"+str(n+1) + ": " + "%.7f"%(output_val) +"\n"

f = open ("B.out", "w+")
f.write(output)
f.close()



