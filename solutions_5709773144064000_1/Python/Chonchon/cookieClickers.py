f = open("/Users/vchoubard/Downloads/B-large.in", "r")
output = open("/Users/vchoubard/Downloads/output.txt", "w")

T = int(f.readline()) + 1

for caseNum in range(1, T):
    farm_cost, extra_cookies, goal = map(float, f.readline().split(" "))
    number_of_cookie_by_sec = 2
    current_cookies = 0
    current_time = 0

    time_to_goal_with_farm = farm_cost/number_of_cookie_by_sec + goal/(number_of_cookie_by_sec+extra_cookies)
    time_to_goal_without_farm = goal/number_of_cookie_by_sec
    while time_to_goal_with_farm < time_to_goal_without_farm:
        current_time += farm_cost/number_of_cookie_by_sec
        number_of_cookie_by_sec += extra_cookies

        time_to_goal_with_farm = farm_cost/number_of_cookie_by_sec + goal/(number_of_cookie_by_sec+extra_cookies)
        time_to_goal_without_farm = goal/number_of_cookie_by_sec

    current_time += time_to_goal_without_farm

    output.write("Case #" + str(caseNum) + ": {:.7f}\n".format(current_time))

f.close()
output.close()