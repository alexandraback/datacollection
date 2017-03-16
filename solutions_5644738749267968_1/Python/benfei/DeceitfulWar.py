__author__ = 'Ben'

from string import Template


def main():
    T = int(input())
    result = ""
    result_line = Template('Case #$x: $y $z\n')

    for instance in range(1, T + 1):
        N = int(input())
        naomi_war = sorted(map(float, input().split()))
        naomi_deceitful_war = []
        naomi_deceitful_war.extend(naomi_war)
        ken_war = sorted(map(float, input().split()))
        ken_deceitful_war = []
        ken_deceitful_war.extend(ken_war)

        war_points = 0
        for turn in range(0, N):
            naomi_play = naomi_war.pop(0)
            if naomi_play > ken_play(ken_war, naomi_play):
                war_points += 1

        deceitful_war_points = 0
        for turn in range(0, N):
            for i in range(1, N-turn+1):
                if ken_deceitful_war[N-turn-i] > naomi_deceitful_war[N-turn-i]:
                    naomi_told = ken_deceitful_war[N-turn-i] - 0.000001
                    break
            else:
                naomi_told = ken_deceitful_war[-1] + 0.0000000001*turn if naomi_deceitful_war[0]>ken_deceitful_war[0] else naomi_deceitful_war[0]

            naomi_play = naomi_deceitful_war.pop(0)
            if naomi_play > ken_play(ken_deceitful_war, naomi_told):
                deceitful_war_points += 1

        result += result_line.substitute(x=instance, y=deceitful_war_points, z=war_points)

    print(result[:-1], end='')


def ken_play(ken_blocks, naomi_play):
    for i in range(len(ken_blocks)):
        if ken_blocks[i] > naomi_play:
            return ken_blocks.pop(i)
    else:
        return ken_blocks.pop(0)


if __name__ == "__main__":
    main()