f = open("/Users/vchoubard/Downloads/D-small-attempt0.in", "r")
output = open("/Users/vchoubard/Downloads/output.txt", "w")


def war(naomi_masses, ken_masses):
    naomi_masses = list(naomi_masses)
    ken_masses = list(ken_masses)
    point = 0
    while len(naomi_masses) != 0:
        naomi_choose = naomi_masses.pop(0)
        ken_choose = ken_choise(ken_masses, naomi_choose)
        point += judge(naomi_choose, ken_choose)
    return point


def judge(naomi_choose, ken_choose):
    if naomi_choose > ken_choose:
        return 1
    else:
        return 0


def ken_choise(ken_masses, naomi_choise):
    ken_bigger = [ken_masses[j] for j in range(0, len(ken_masses)) if ken_masses[j] > naomi_choise]
    ken_bigger.sort()
    if len(ken_bigger) == 0:
        ken_choise = ken_masses.pop(0)
    else:
        ken_choise = ken_masses.pop(ken_masses.index(ken_bigger[0]))
    return ken_choise


def decei(naomi_masses, ken_masses):
    naomi_masses = list(naomi_masses)
    ken_masses = list(ken_masses)
    point = 0
    while len(naomi_masses) != 0:
        naomi_said, naomi_played = naomi_choise(naomi_masses, ken_masses)
        ken_choose = ken_choise(ken_masses, naomi_said)
        point += judge(naomi_played, ken_choose)
    return point

def naomi_choise(naomi_masses, ken_masses):
    len_ken_masses = len(ken_masses)
    ken_bigger = ken_masses[len_ken_masses-1]
    ken_smaller = ken_masses[0]
    naomi_smaller = naomi_masses[0]
    if naomi_smaller < ken_smaller:
        naomi_said = ken_bigger - 0.00001
        naomi_played = naomi_masses.pop(0)

    else:
        naomi_said = ken_bigger + 0.00001
        naomi_played = naomi_masses.pop(0)
    return naomi_said, naomi_played


def get_masses():
    f.readline()
    naomi_masses = map(float, f.readline().split(" "))
    ken_masses = map(float, f.readline().split(" "))
    naomi_masses.sort()
    ken_masses.sort()
    return naomi_masses, ken_masses


def main():
    T = int(f.readline())
    for test_case in range(T):
        naomi_masses_sorted, ken_masses_sorted = get_masses()
        point_war = war(naomi_masses_sorted, ken_masses_sorted)
        point_decei = decei(naomi_masses_sorted, ken_masses_sorted)
        output.write("Case #" + str(test_case+1) + ": " + str(point_decei) + " " + str(point_war) + "\n")
        # print "Case #" + str(test_case+1) + ": " + str(point_decei) + " " + str(point_war)


main()

f.close()
output.close()
