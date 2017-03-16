import sys
from pprint import pprint

PREC = 0.0000001

def solve():
    cars = int(sys.stdin.readline().strip())
    left_lane = []
    right_lane = []
    for i in range(cars):
        line = sys.stdin.readline().strip()
        splitted = line.strip().split(" ")
        lane = left_lane if splitted[0] == "L" else right_lane
        lane.append({
            "speed": int(splitted[1]),
            "pos": float(splitted[2]),
        })

    left_lane.sort(key=lambda x: x["pos"])
    right_lane.sort(key=lambda x: x["pos"])

    def get_next_collision_time_lane(lane):
        next_collision_time = None
        for i in range(len(lane) - 1):
            car1 = lane[i]
            car2 = lane[i + 1]
            if car1["speed"] > car2["speed"]:
                time = (car2["pos"] - car1["pos"] - 5) / (car1["speed"] - car2["speed"])
                if next_collision_time is None or time < next_collision_time:
                    next_collision_time = time

        return next_collision_time

    def get_next_collision_time():
        time_left = get_next_collision_time_lane(left_lane)
        time_right = get_next_collision_time_lane(right_lane)
        if time_left is None:
            return time_right

        if time_right is None:
            return time_left

        return min(time_left, time_right)

    def update_state(time_elapsed):
        for car in left_lane + right_lane:
            car["pos"] += car["speed"] * time_elapsed

    def try_fix_collision_lane(this_lane, other_lane):
        i = len(this_lane) - 2
        fixed = False
        while i >= 0:
            car1 = this_lane[i]
            car2 = this_lane[i + 1]
            if car2["pos"] - car1["pos"] - 5 < PREC:
                car_back = None
                car_front = None
                can_move_car1 = True
                can_move_car2 = True
                for other_car in other_lane:
                    dist = abs(other_car["pos"] - car1["pos"])
                    if dist < 5:
                        can_move_car1 = False

                    dist = abs(other_car["pos"] - car2["pos"])
                    if dist < 5:
                        can_move_car2 = False

                    if other_car["pos"] < car1["pos"]:
                        car_back = other_car
                    elif other_car["pos"] > car2["pos"] and car_front is None:
                        car_front = other_car

                target_car = None
                if can_move_car1 and can_move_car2:
                    car1_speed_diff = 0
                    car2_speed_diff = 0
                    if car_back and car1["speed"] < car_back["speed"]:
                        car1_speed_diff = car_back["speed"] = car1["speed"]

                    if car_front and car1["speed"] > car_front["speed"]:
                        diff = car1["speed"] - car_front["speed"]
                        if diff > car1_speed_diff:
                            car1_speed_diff = diff

                    if car_back and car2["speed"] < car_back["speed"]:
                        car2_speed_diff = car_back["speed"] = car2["speed"]

                    if car_front and car2["speed"] > car_front["speed"]:
                        diff = car2["speed"] - car_front["speed"]
                        if diff > car2_speed_diff:
                            car2_speed_diff = diff

                    if car1_speed_diff < car2_speed_diff:
                        target_car = car1
                    elif car1_speed_diff > car2_speed_diff:
                        target_car = car2
                    else:
                        if car_back and car_front and car1["pos"] - car_back["pos"] > car_front["pos"] - car2["pos"]:
                            target_car = car1
                        else:
                            target_car = car2

                elif can_move_car1:
                    target_car = car1
                elif can_move_car2:
                    target_car = car2

                if target_car is None:
                    return False

                # print("Moving", target_car, "to another lane")
                this_lane.remove(target_car)
                other_lane.append(target_car)
                fixed = True

            i -= 1

        if fixed:
            other_lane.sort(key=lambda x: x["pos"])

        return True


    time_elapsed = 0.0
    while True:
        next_collision = get_next_collision_time()
        if next_collision is None:
            return "Possible"

        if next_collision < PREC:
            return time_elapsed

        update_state(next_collision)
        time_elapsed += next_collision
        # print("Collision:", time_elapsed)
        # print("Left:")
        # pprint(left_lane)
        # print("Right:")
        # pprint(right_lane)
        if not try_fix_collision_lane(left_lane, right_lane) or not try_fix_collision_lane(right_lane, left_lane):
            return time_elapsed

def run():
    cases = int(sys.stdin.readline().strip())
    for i in range(cases):
        print("Case #{}: {}".format(i + 1, solve()))

if __name__ == "__main__":
    run()

