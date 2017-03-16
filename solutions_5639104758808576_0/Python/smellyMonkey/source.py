in_file = open("data.in")
out_file = open("data.out", "w")

lines = in_file.readlines()

line_num = 0

T = int(lines[line_num])
line_num += 1

for ca in range(1, T+1):
    cur_line = lines[line_num].split()
    line_num += 1

    s_max = int(cur_line[0])
    num_of_sh = list(cur_line[1])
    num_of_sh = [int(x) for x in num_of_sh]

    ans = 0
    cur_num = 0
    for i in range(s_max+1):
        if i <= cur_num:
            cur_num += num_of_sh[i]
        else:
            needed = i - cur_num
            ans += needed
            cur_num += needed + num_of_sh[i]

    out_file.write("Case #{0}: {1}\n".format(ca, ans))

in_file.close()
out_file.close()
