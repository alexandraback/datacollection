f = open("C.in")
num = int(f.readline())
output = ""
for nnn in range(num):
    N, M = [int(x) for x in f.readline().strip().split(" ")]
    zips = []
    for n in range(N):
        zips.append(f.readline().strip())

    flights = []
    for m in range(M):
        d,i = [int(x) for x in f.readline().strip().split(" ")]
        flights.append((d,i))
        flights.append((i,d))

    global_zips = zips
    global_flights = flights

    def get_num(state):
        at_city, zips_left, zip_str, flights_left, returns = state
        return -int("".join(zip_str))

    def sort_states(states):
        return sorted(states, key=get_num)
    #context = (at_city, zips left, zips_str, flights_left, returns)
    def make_brute(state):
        #first return
        at_city, zips_left, zip_str, flights_left, returns = state

        if len(returns) > 0:
            ret = returns[0:-1]
            return_state = (returns[-1], zips_left, zip_str, flights_left,  ret)
            ret_states = make_brute(return_state)
        else:
            ret_states = []

        for flight in flights_left:
            if flight[0] == at_city:

                rets = returns[:]
                rets.append(flight[0])

                z_left = zips_left[:]
                #print z_left, flight
                #print state
                trial = global_zips[flight[1]-1]
                if trial not in z_left:
                    continue
                z_left.remove(trial)
                z_str = zip_str[:]
                z_str.append(global_zips[flight[1]-1])

                f_left = flights_left[:]
                f_left.remove(flight)
                new_state = flight[1], z_left, z_str, f_left, rets
                ret_states.append(new_state)
        
        return sort_states(ret_states)
    init_states = []
    for on_city in range(N):
        in_zip = zips[:]
        z_str = [in_zip.pop(on_city)]
        init_state = (on_city+1, in_zip, z_str, flights, [])
        init_states.append(init_state)
    init_states = sort_states(init_states)
    

    def print_states(states):
        print "===="
        for k in states:
            print k
        print "===="

    states = init_states

    #print_states(states)

    done_states = []
    while len(states) != 0:
        state = states.pop(-1)
        at_city, zips_left, zip_str, flights_left, returns = state
        if len(zips_left) == 0:
            done_states.append(state)
            break #depth first yo
        states.extend(make_brute(state))
        #print_states(states)
        #raw_input()
    

    def get_nums(states):
        nums = []
        for state in states:
            at_city, zips_left, zip_str, flights_left, returns = state
            nums.append(int("".join(zip_str)))
        return nums
    def print_nums(states):
        nums = []
        for state in states:
            at_city, zips_left, zip_str, flights_left, returns = state
            nums.append(zip_str)
        return nums
    output_val = str(min(get_nums(done_states)))

    output_i = "Case #"+str(nnn+1) + ": " + output_val +"\n"
    print output_i,
    output += output_i

f2 = open ("C.out", "w+")
f2.write(output)
f2.close()



