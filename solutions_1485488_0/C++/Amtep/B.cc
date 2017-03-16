#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

class node {
public:
    double time;
    int x, y;

    node(double time, int x, int y) {
        this->time = time;
        this->x = x;
        this->y = y;
    }

    friend bool operator< (const node & self, const node & other) {
        return self.time > other.time;
    }
};

class caves {
public:
    int height, width;
    std::vector<int> floorinfo;
    std::vector<int> ceilinfo;
    std::vector<double> best_time;
    double maxtime;

    caves(int height, int width) {
        this->height = height;
        this->width = width;
    }

    int floor_at(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return 0;
        return this->floorinfo[x + y * width];
    }

    int ceil_at(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return 0;
        return this->ceilinfo[x + y * width];
    }

    double time_at(int x, int y) {
        if (x < 0 || x >= width || y < 0 || y >= height)
            return maxtime;
        return this->best_time[x + y * width];
    }

    node calc_move(int water, const node & here, int dx, int dy) {
        node step(this->maxtime, here.x + dx, here.y + dy);
        int ceil_step = ceil_at(step.x, step.y);
        int floor_here = floor_at(here.x, here.y);
        if (ceil_step - floor_here < 50)
            return step;
        int floor_step = floor_at(step.x, step.y);
        if (ceil_step - floor_step < 50)
            return step;
        int ceil_here = ceil_at(here.x, here.y);
        if (ceil_here - floor_step < 50)
            return step;
        step.time = here.time;
        double water_now = water - here.time * 10;
        if (ceil_step - water_now < 50) {
            water_now = ceil_step - 50;
            step.time = (water - water_now) / 10;
        }
        if (step.time > 0) {
            if (water_now - floor_here < 20)
               step.time += 10;
            else
               step.time += 1;
        }
        return step;
    }

    double solve(int water) {
        std::priority_queue<node> todo;
        this->maxtime = water * 10 + (this->height * this->width) * 10;
        this->best_time.resize(this->height * this->width);
        for (int i = 0; i < this->height * this->width; i++)
            this->best_time[i] = maxtime + 10;

        todo.push(node(0, 0, 0));
        for (;;) {
            node next = todo.top();
            todo.pop();
            if (next.time >= this->time_at(next.x, next.y))
                continue;
            this->best_time[next.x + next.y * this->width] = next.time;
            if (next.x == this->width - 1 && next.y == this->height - 1)
                return next.time;
            node step = this->calc_move(water, next, -1, 0);
            if (step.time < this->time_at(step.x, step.y))
                todo.push(step);
            step = this->calc_move(water, next, +1, 0);
            if (step.time < this->time_at(step.x, step.y))
                todo.push(step);
            step = this->calc_move(water, next, 0, -1);
            if (step.time < this->time_at(step.x, step.y))
                todo.push(step);
            step = this->calc_move(water, next, 0, +1);
            if (step.time < this->time_at(step.x, step.y))
                todo.push(step);
        }
    }
};

int main(void)
{
    int ncases;

    std::cin >> ncases;
    std::cin.ignore();
    for (int casenr = 1; casenr <= ncases; casenr++) {
      int water, height, width;

      std::cin >> water >> height >> width;
      std::cin.ignore();
      caves cave = caves(height, width);
      for (int i = 0; i < height; i++) {
          for (int j = 0; j < width; j++) {
              int ceiling;
              std::cin >> ceiling;
              cave.ceilinfo.push_back(ceiling);
          }
          std::cin.ignore();
      }
      for (int i = 0; i < height; i++) {
          for (int j = 0; j < width; j++) {
              int floor;
              std::cin >> floor;
              cave.floorinfo.push_back(floor);
          }
          std::cin.ignore();
      }

      double best_time = cave.solve(water);

      std::cout << std::setprecision(9);
      std::cout << "Case #" << casenr << ": " << best_time << "\n";
      std::cerr << std::setprecision(9);
      std::cerr << "Case #" << casenr << ": " << best_time << "\n";
    }
}
